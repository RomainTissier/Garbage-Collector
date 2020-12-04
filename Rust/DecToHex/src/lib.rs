//! Small program that convert uint to hex (and vice versa)

#![warn(
    missing_docs,
    absolute_paths_not_starting_with_crate,
    anonymous_parameters,
    box_pointers,
    clashing_extern_declarations,
    deprecated_in_future,
    elided_lifetimes_in_paths,
    explicit_outlives_requirements,
    indirect_structural_match,
    keyword_idents,
    macro_use_extern_crate,
    meta_variable_misuse,
    missing_copy_implementations,
    missing_crate_level_docs,
    missing_debug_implementations,
    missing_doc_code_examples,
    non_ascii_idents,
    private_doc_tests,
    single_use_lifetimes,
    trivial_casts,
    trivial_numeric_casts,
    unaligned_references,
    unreachable_pub,
    unsafe_code,
    unstable_features,
    unused_crate_dependencies,
    unused_extern_crates,
    unused_import_braces,
    unused_lifetimes,
    unused_qualifications,
    unused_results,
    variant_size_differences
)] // unsafe_op_in_unsafe_fn is unstable
#![warn(clippy::all)]

/// Convert a String from UInt to hex format OR from Hex to Int format
///
/// Example 1:
/// ```
/// let res = hex_uint_converter::convert_uint_or_hex(String::from("1")).unwrap();
/// ```
pub fn convert_uint_or_hex(str_to_parse: String) -> Result<String, String> {
    if str_to_parse.contains("0x") {
        // Try to parse Hex to Int
        let formated_str = str_to_parse.trim_start_matches("0x");
        let number = match u128::from_str_radix(&formated_str, 16) {
            Ok(n) => n,
            Err(_) => {
                return Err(format!(
                    "Error, the value {:?} is not an hexadecimal value!",
                    str_to_parse
                ))
            }
        };
        Ok(number.to_string())
    } else {
        // Try to parse Int to Hex
        let number: u128 = match str_to_parse.parse() {
            Ok(n) => n,
            Err(_) => {
                return Err(format!(
                    "Error, the value {:?} is not an unsigned integer!",
                    str_to_parse
                ))
            }
        };
        Ok(format!("0x{:x}", number))
    }
}

#[test]
fn basic_tests() {
    assert_eq!(convert_uint_or_hex(String::from("1")).unwrap(), "0x1");
    assert_eq!(convert_uint_or_hex(String::from("0x1")).unwrap(), "1");
    assert_eq!(convert_uint_or_hex(String::from("0xF")).unwrap(), "15");
    assert_eq!(convert_uint_or_hex(String::from("15")).unwrap(), "0xf");
    assert_eq!(
        convert_uint_or_hex(String::from("bad_value")).is_err(),
        true
    );
    assert_eq!(
        convert_uint_or_hex(String::from("0xbad_value")).is_err(),
        true
    );
}
