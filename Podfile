# Uncomment the next line to define a global platform for your project
platform :ios, '13.0'
plugin 'cocoapods-xcremotecache'

use_frameworks! :linkage => :static


install! 'cocoapods', :generate_multiple_pod_projects => true

xcremotecache({
    'cache_addresses' => ['https://my-cached-domain/cache/demo/'],
    'primary_repo' => 'git@github.com:canhth/demo-xcremote-cache.git',
    'mode' => 'producer',
    'primary_branch' => 'master',
    'check_build_configuration' => 'Debug',
    'check_platform' => 'iphonesimulator',
    'prettify_meta_files' => true,
    'final_target' => 'Proj',
    'custom_rewrite_envs' => ['PODS_TARGET_SRCROOT', 'BUILT_PRODUCTS_DIR', 'TARGET_BUILD_DIR', 'FRAMEWORKS_FOLDER_PATH', 'FRAMEWORK_SEARCH_PATHS'],
    'enabled' => true
})

target 'Proj' do
  pod 'FaceDetection', :path => 'Modules/FaceDetection/'
  pod 'SwiftyRSA'

end

target 'WatchCache Watch App' do
  # Comment the next line if you don't want to use dynamic frameworks
  platform :watchos, '6.0'
  pod 'PromiseKit'
  pod 'SwiftyRSA'
end

post_install do |installer|
installer.pod_target_subprojects.flat_map(&:targets).each do |target|
  target.build_configurations.each do |config|
    config.build_settings['ENABLE_BITCODE'] = 'YES'
    config.build_settings['APPLICATION_EXTENSION_API_ONLY'] = 'NO'
    config.build_settings['GCC_PREPROCESSOR_DEFINITIONS'] = ['$(inherited)']

    config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '13.0'
    config.build_settings['DEBUG_INFORMATION_FORMAT'] = 'dwarf'

    config.build_settings['SWIFT_ACTIVE_COMPILATION_CONDITIONS'] = ['$(inherited)', 'DEBUG']
    config.build_settings['GCC_PREPROCESSOR_DEFINITIONS'] << 'DEBUG=1'
    config.build_settings['SWIFT_OPTIMIZATION_LEVEL'] = '-Onone'
    config.build_settings['GCC_OPTIMIZATION_LEVEL'] = '0'
    config.build_settings['ENABLE_TESTABILITY'] = 'YES'
    config.build_settings['EXCLUDED_ARCHS[sdk=iphonesimulator*]'] = 'arm64'
  end
end
end
