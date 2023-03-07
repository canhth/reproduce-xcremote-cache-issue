Pod::Spec.new do |s|
  s.name             = 'FaceDetection'
  s.version          = '0.1.0'
  s.summary          = 'A short description of FaceDetection.'
  s.homepage         = 'https://github.com/FaceDetection'
  s.license          = 'All rights reserved.'
  s.author           = { 'Canh' => 'app@canh.tran.com' }
  s.source           = { git: 'https://github.com/FaceDetection', tag: s.version.to_s }
  s.swift_version    = '5.1'

  s.ios.deployment_target   = '13.0'
#  s.ios.vendored_frameworks = 'FaceDetection/Frameworks/*.framework'
  s.ios.deployment_target   = '12.0'
  s.watchos.deployment_target = '6.0'
  s.static_framework = true

  s.source_files = 'FaceDetection/Classes/**/*'
  s.resource = 'FaceDetection/Assets/MGLivenessDetectionResource.bundle'
  s.resource_bundles = {
    'FaceDetection' => ['FaceDetection/Assets/**/*.storyboard', 'FaceDetection/Assets/**/*.xcassets']
  }

  s.dependency 'PromiseKit'
  s.dependency 'SwiftMessages'
end
