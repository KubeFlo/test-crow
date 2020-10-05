cc_binary(
    name = "crow_client_bin",
    srcs = ["src/client.cpp"],
    linkopts = ["-lcurl"]
)

load("@io_bazel_rules_docker//container:container.bzl", "container_image")

container_image(
    name = "v1",
    base = "@centos7_with_curl//image",
    files = [":crow_client_bin"],
    entrypoint = ["./crow_client_bin"],
    stamp = True,
    repository = "crow",
    labels = {
        "com.crow.client": "v1"
    }
)
