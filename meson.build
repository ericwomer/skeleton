project(
    'Skeletal Application Framework',
    'cpp',
    version : '0.0.0', # This is oveverridden in the conf_data section
    default_options: 
    [
        'cpp_std=c++14',
        'b_lundef=false',
        'b_sanitize=none',
        'warning_level=3'
    ],
    meson_version: '>=0.48.0'
)

pkgconfig = import('pkgconfig')

cpp = meson.get_compiler('cpp')

conf_data = configuration_data()
conf_data.set('name', meson.project_name())

conf_data.set('compiler_name', cpp.get_id())
conf_data.set('compiler_version', cpp.version())
conf_data.set('host_machine', host_machine.system())
conf_data.set('cpu_family', build_machine.cpu_family())

conf_data.set('major', '0')
conf_data.set('minor', '0')
conf_data.set('patch', '1')
conf_data.set('compile', '0')

configure_file(input : 'src/config.h.in',
              output : 'config.h',
              configuration : conf_data)

skeleton_src = [
    'src/skeletonapp.cpp',
    'src/main.cpp'
]

skeleton_include_directories = [
    include_directories('src/'),
    include_directories('include/'),
	include_directories('thirdparty/include/'),
    include_directories('/usr/lib/llvm-8/include/c++/v1/')
    ]

skeleton_cflags = ['-stdlib=libc++']
skeleton_ldflags = [
    '-lm',
    '-lc++',
    '-lc++abi']


skeleton_deps = []

skeleton = executable(
    'skeleton', 
    skeleton_src,
    dependencies: skeleton_deps,
    include_directories: skeleton_include_directories,
    cpp_args: skeleton_cflags,
    link_args: skeleton_ldflags
)
