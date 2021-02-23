//! This file contains the main function

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

use vector_inheritance::Info;
use vector_inheritance::InfoList;
use vector_inheritance::InfoListMethod;

/// Entry point of the program
fn main() {
    let info_0 = Info { i: 1, j: 2 };
    let info_1 = Info { i: 3, j: 4 };
    let info_2 = Info { i: 5, j: 6 };
    let info_list: InfoList = vec![info_0, info_1, info_2];
    let res = info_list.get_from_i(3);
    print!("{:?}", res);
}
