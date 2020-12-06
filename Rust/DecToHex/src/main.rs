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

use hex_uint_converter::convert_uint_or_hex;
use std::env;

// Entry point of the program
fn main() {
    // Get arguments except first one (first argument is the name of the program)
    let args: Vec<String> = env::args().skip(1).collect();

    for arg in args {
        match convert_uint_or_hex(&arg) {
            Ok(n) => print!("{} ", n),
            Err(e) => panic!(e),
        };
    }
    println!();
}
