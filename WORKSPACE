workspace(name = "test_crow")

load("@//third_party:deps.bzl", "cc_deps")

cc_deps()


#DOCKER  
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Download the rules_docker repository at release v0.14.4
http_archive(
    name = "io_bazel_rules_docker",
    sha256 = "480daa8737bf4370c1a05bfced903827e75046fea3123bd8c81389923d968f55",
    strip_prefix = "rules_docker-0.11.0",
    urls = ["https://github.com/bazelbuild/rules_docker/releases/download/v0.11.0/rules_docker-v0.11.0.tar.gz"],
)

load(
    "@io_bazel_rules_docker//toolchains/docker:toolchain.bzl",
    docker_toolchain_configure="toolchain_configure"
)

docker_toolchain_configure(
    name = "docker_config",
    docker_path = "/usr/bin/docker",
)

load("@io_bazel_rules_docker//repositories:repositories.bzl", container_repositories = "repositories",)
container_repositories()

load("@io_bazel_rules_docker//repositories:deps.bzl", container_deps = "deps")
container_deps()

load("@io_bazel_rules_docker//repositories:pip_repositories.bzl", "pip_deps")
pip_deps()

load(
    "@io_bazel_rules_docker//container:container.bzl",
    "container_pull",
)

load(
    "@io_bazel_rules_docker//cc:image.bzl",
    _cc_image_repos = "repositories",
)


# load CXX optimized docker images
_cc_image_repos()

container_pull(
    name = "cxx_container",
    registry = "index.docker.io",
    repository = "library/centos",
    tag="7",

)
