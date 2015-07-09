# Copyright 2015 Gentoo Foundation
# Distributed under the terms of the GNU General Public License v2
# $Header: $

EAPI="4"

inherit git-r3

DESCRIPTION="MEGA SDK - Client Access Engine"
HOMEPAGE="http://github.com/meganz/sdk"
EGIT_REPO_URI="git://github.com/meganz/sdk.git"

LICENSE="BSD-2"
SLOT="0"
KEYWORDS="~amd64"
IUSE="debug sqlite freeimage sodium"

RDEPEND="!net-misc/megatools
         net-misc/curl[ssl]
         net-dns/c-ares
         dev-libs/openssl
         dev-libs/crypto++
         sys-libs/zlib
         sys-libs/readline
         sqlite? ( dev-db/sqlite )
         freeimage? ( media-libs/freeimage )
         sodium? ( dev-libs/libsodium )"
DEPEND="${RDEPEND}"

src_prepare() {
    ./autogen.sh
}

src_configure() {
    # static-libs, {python, php, java} bindings, doxygen docs disabled
    # if you want them, add useflags
    econf \
	$(use_enable debug) \
	$(use_with sqlite) \
	$(use_with freeimage) \
	$(use_with sodium) \
	--without-termcap \
	--disable-doxygen-doc \
	--disable-curl-checks
}
