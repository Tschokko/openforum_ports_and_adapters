load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")
load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")

cc_library(
    name = "demo",
    srcs = glob(
        [
            "src/**/*.cpp",
            "src/**/*.ipp",
        ],
        exclude = [
            "src/eventd/main.cpp",
        ],
    ),
    hdrs = glob([
        "include/**/*.hpp",
        "src/**/*.hpp",
    ]),
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "eventd",
    srcs = ["src/eventd/main.cpp"],
    deps = [
        "//demo",
    ],
)

cc_test(
    name = "tests",
    srcs = glob(["tests/**/*.cpp"]),
    deps = [
        "//demo",
        "@googletest//:gtest_main",
    ],
)
