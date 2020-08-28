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
            "src/main.cpp",
        ],
    ),
    hdrs = glob([
        "include/**/*.hpp",
        "src/**/*.hpp",
    ]),
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "user",
    srcs = ["src/main.cpp"],
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

cc_binary(
    name = "httpd",
    srcs = ["src/httpd.c"],
    deps = [
        "//demo",
    ],
    linkopts = [
        "-lmicrohttpd"
    ],
)
