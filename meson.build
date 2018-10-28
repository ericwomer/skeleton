project(
    'skeleton',
    'cpp',
    version : '0.0.0',
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
conf_data.set('major', '1')
conf_data.set('minor', '2')
conf_data.set('patch', '3')
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
