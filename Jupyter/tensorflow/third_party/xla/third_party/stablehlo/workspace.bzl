"""Provides the repository macro to import StableHLO."""

load("//third_party:repo.bzl", "tf_http_archive", "tf_mirror_urls")

def repo():
    # LINT.IfChange
    STABLEHLO_COMMIT = "887e0692ae727555c6b0e00402897742a409de54"
    STABLEHLO_SHA256 = "ffa1d97f4ad96313c94289f2d4343bcec2268a08c9cad841de52e830cc35f9b0"
    # LINT.ThenChange(Google-internal path)

    tf_http_archive(
        name = "stablehlo",
        sha256 = STABLEHLO_SHA256,
        strip_prefix = "stablehlo-{commit}".format(commit = STABLEHLO_COMMIT),
        urls = tf_mirror_urls("https://github.com/openxla/stablehlo/archive/{commit}.zip".format(commit = STABLEHLO_COMMIT)),
        patch_file = [
            "//third_party/stablehlo:temporary.patch",  # Autogenerated, don't remove.
        ],
    )
