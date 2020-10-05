cc_binary(
    name = "crow_server",
    srcs = ["src/server.cpp"],
    deps = ["//third_party/crow:libcrow","//third_party/getTimeOfDay:libtime"],
    linkopts = ["-lpthread"]
)



load("@io_bazel_rules_docker//container:container.bzl", "container_image")

container_image(
    name = "v1",
    base = "@cxx_container//image",
    files = [":crow_server"],
    entrypoint = ["./crow_server"],
    ports = ["9080"],
    stamp = True,
    repository = "pistache",
    labels = {
        "com.pistache.client": "v1"
    }
)
