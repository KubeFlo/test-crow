cc_binary(
    name = "crow_client_bin",
    srcs = ["src/client.cpp"],
    linkopts = ["-lcurl"]
)

load("@io_bazel_rules_docker//container:container.bzl", "container_image","container_push")

container_image(
    name = "client_image",
    base = "@centos7_with_curl//image",
    files = [":crow_client_bin"],
    entrypoint = ["./crow_client_bin"],
    stamp = True,
    repository = "crow",
    labels = {
        "com.crow.client": "v1"
    }
)

container_push(
   name = "client_push",
   image = ":client_image",
   format = "Docker",
   registry = "docker.pkg.github.com",
   repository = "kubecorn/test-crow/client",
   #tag = "v1",
   tag = "{BUILD_EMBED_LABEL}"

)
