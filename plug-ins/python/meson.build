python_plugins = [
  { 'name': 'colorxhtml' },
  { 'name': 'file-openraster' },
  { 'name': 'foggify' },
  { 'name': 'gradients-save-as-css' },
  { 'name': 'histogram-export' },
  { 'name': 'palette-export-as-kpl' },
  { 'name': 'palette-offset' },
  { 'name': 'palette-sort' },
  { 'name': 'palette-to-gradient' },
  { 'name': 'python-eval' },
  { 'name': 'spyro-plus' },
]

if not stable or not release
  python_plugins += [
    { 'name': 'test-dialog' },
  ]
endif

subdir('python-console')
subdir('tests')

foreach plugin : python_plugins
  name = plugin.get('name')
  srcs = plugin.get('srcs', [name + '.py'])

  install_data(srcs, install_dir: gimpplugindir / 'plug-ins' / name,
               install_mode: 'rwxr-xr-x')

  foreach src : srcs
    # Ugly trick to copy Python plug-ins into subfolders so that we can run GIMP
    # from the build directory without installing it.
    # To be run even if we don't install Python plug-ins so that we can
    # still run them for in-build scripts.
    run_command(python, meson.project_source_root() / 'build/meson/cp-plug-in-subfolder.py',
                meson.current_source_dir() / src, meson.current_build_dir() / name, check: true)
  endforeach
endforeach

# Fallback fix to the problem of non-configured interpreters (needed by MSIX)
if platform_windows and not meson.is_cross_build() and python.found()
  python_config = configuration_data()
  if not stable or not release
    #python.exe is prefered in unstable versions because of error output
    python_config.set('PYTHON_EXE', 'python.exe')
  else
    #pythonw.exe is prefered in stable releases because it works silently
    python_config.set('PYTHON_EXE', 'pythonw.exe')
  endif

  configure_file(input : 'pygimp.interp.in',
                 output: 'pygimp.interp',
                 configuration: python_config,
                 install: true,
                 install_dir: gimpplugindir / 'interpreters')
endif
