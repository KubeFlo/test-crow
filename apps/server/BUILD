cc_binary(
    name = "crow_server_bin",
    srcs = ["src/server.cpp"],
    deps = ["//third_party/Config:libconfig","//third_party/crow:libcrow","//third_party/getTimeOfDay:libtime"],
    linkopts = ["-lpthread"],
    visibility = ["//visibility:public"],
)

load("@io_bazel_rules_docker//container:container.bzl", "container_image", "container_push")

container_image(
    name = "server_image",
    base = "@cxx_container//image",
    files = [":crow_server_bin"],
    entrypoint = ["./crow_server_bin"],
    ports = ["9080"],
    stamp = True,
    repository = "crow",
    labels = {
        "com.crow.server": "v1"
    }
)


container_push(
   name = "server_push",
   image = ":server_image",
   format = "Docker",
   registry = "docker.pkg.github.com",
   repository = "kubecorn/test-crow/server",
   tag = "v1",
  #tag = "{BUILD_EMBED_LABEL}"

)

