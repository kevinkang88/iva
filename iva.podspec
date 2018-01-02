#
# Be sure to run `pod lib lint iva.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'iva'
  s.version          = '0.1.0'
  s.summary          = 'Instant verification with mobile carriers'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
SDK that handles instant verification with mobile carriers
                       DESC

  s.homepage         = 'https://www.neustar.biz/'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'kevinkang88' => 'kevinkang88@gmail.com' }
  s.source           = { :git => 'https://github.com/kevinkang88/iva.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'iva/Classes/**/*'
  
  # s.resource_bundles = {
  #   'iva' => ['iva/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'

  s.frameworks = 'CoreTelephony'
  s.dependency 'AFNetworking', '~> 2.3'
  s.dependency 'PromiseKit'
  s.dependency 'OHHTTPStubs'
  s.subspec 'SimilityBeacon' do |sb|
    sb.source_files = 'iva/Assets/*.h'
    sb.preserve_paths = 'iva/Assets/*.h'
    sb.vendored_libraries = 'iva/Assets/*.a'
    sb.xcconfig = { 'HEADER_SEARCH_PATHS' => "${PODS_ROOT}/#{s.name}/Assets/*" }
  end

  s.subspec 'Confirm' do |sb|
    sb.source_files = 'iva/Assets/*.framework'
    sb.vendored_framework = 'iva/Assets/confirm_sdk.framework'
    sb.xcconfig = { 'HEADER_SEARCH_PATHS' => "${PODS_ROOT}/#{s.name}/Assets/*" }
  end
end
