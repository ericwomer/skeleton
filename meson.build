project(
    'template',
    'cpp',
    version : '0.0.0',
    default_options: 
    [
        'cpp_std=c++17',
        'b_lundef=false',
        'b_sanitize=none',
        'warning_level=3'
    ],
    meson_version: '>=0.48.0'
)

pkgconfig = import('pkgconfig')

cpp = meson.get_compiler('cpp')

template_src = [
    ]

template_include_directories = [
    include_directories('src/'),
    include_directories('include/'),
	include_directories('thirdparty/include/')
    include_directories('/usr/lib/llvm-8/include/c++/v1/')
    ]

template_cflags = ['-stdlib=libc++']
template_ldflags = [
    '-lm',
    '-lc++',
    '-lc++abi']


template_deps = []

template = executable(
    'template', 
    template_src,
    dependencies: template_deps,
    include_directories: template_include_directories,
    cpp_args: template_cflags,
    link_args: template_ldflags
)
