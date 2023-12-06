cdata = configuration_data()
cdata.set('TOP_SRCDIR', meson.global_source_root())
cdata.set('TOP_BUILDDIR', meson.global_build_root())
cdata.set('OUTPUT_DIR', join_paths(meson.global_build_root(),'Documents'))
cdata.set('README_PATH', join_paths(meson.global_source_root(),'README.md'))
cdata.set('VERSION', meson.project_version())
cdata.set('PROJECT_NAME', meson.project_name())
cdata.set('PROJECT_BRIEF', 'Project Brief')
cdata.set('FONT_NAME', 'SauceCodePro')

doxyfile = configure_file(input: 'Doxyfile.in',
                          output: 'Doxyfile',
                          configuration: cdata,
                          install: false
                          )

doxygen = find_program('doxygen')

doc_target = run_target(
    'docs',
    command: 
    [
        doxygen, doxyfile
    ]
    )