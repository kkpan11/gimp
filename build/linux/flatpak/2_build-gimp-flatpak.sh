#!/bin/sh

# Flatpak design mandates to build natively
ARCH=$(uname -m)


if [ -z "$GITLAB_CI" ] && [ "$1" != '--ci' ]; then
  # Make the script work locally
  if [ "$0" != 'build/linux/flatpak/2_build-gimp-flatpak.sh' ]; then
    echo 'To run this script locally, please do it from to the gimp git folder'
    exit 1
  fi
  git submodule update --init
  flatpak update -y
  if [ -z "$GIMP_PREFIX" ]; then
    export GIMP_PREFIX="$PWD/../_install-$ARCH"
  fi

  # Build GIMP only
  if [ ! -f "_build-$ARCH/build.ninja" ]; then
    mkdir -p _build-$ARCH && cd _build-$ARCH
    flatpak-builder --run --ccache "$GIMP_PREFIX" ../build/linux/flatpak/org.gimp.GIMP-nightly.json meson setup .. -Dprefix=/app/ -Dlibdir=/app/lib/
    if [ ! -f '.gitignore' ]; then
      echo '*' > .gitignore
    fi
  else
    cd _build-$ARCH
  fi
  flatpak-builder --run --ccache "$GIMP_PREFIX" ../build/linux/flatpak/org.gimp.GIMP-nightly.json ninja
  flatpak-builder --run "$GIMP_PREFIX" ../build/linux/flatpak/org.gimp.GIMP-nightly.json ninja install


elif [ "$GITLAB_CI" ] || [ "$1" = '--ci' ]; then
  export GIMP_PREFIX="$PWD/_install-$ARCH"

  if [ "$1" != '--ci' ]; then
    # Extract deps from previous job
    echo 'Extracting previously built dependencies'
    tar xf .flatpak-builder.tar
  fi

  # GNOME script to customize gimp module in the manifest (not needed)
  #rewrite-flatpak-manifest build/linux/flatpak/org.gimp.GIMP-nightly.json gimp ${CONFIG_OPTS}

  # Build GIMP only
  flatpak-builder --force-clean --user --disable-rofiles-fuse --keep-build-dirs --build-only \
                  "$GIMP_PREFIX" build/linux/flatpak/org.gimp.GIMP-nightly.json
  if [ "$1" != '--ci' ]; then
    tar cf gimp-meson-log.tar .flatpak-builder/build/gimp-1/_flatpak_build/meson-logs/meson-log.txt
  fi

  # Cleanup GIMP_PREFIX and export it to OSTree repo
  flatpak-builder --user --disable-rofiles-fuse --finish-only --repo=repo \
                  "$GIMP_PREFIX" build/linux/flatpak/org.gimp.GIMP-nightly.json
  if [ "$1" != '--ci' ]; then
    tar cf repo.tar repo/
  fi
fi