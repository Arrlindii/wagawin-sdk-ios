
Pod::Spec.new do |s|
  s.name             = 'WagawinSDK'
  s.version          = '2.0.4'
  s.summary          = 'The Wagawin Ad Network SDK'

  s.description      = <<-DESC
The Wagawin SDK will allow you to connect your app to the Wagawin Ad Network and display Wagawin Ads in your native iOS application.
                       DESC

  s.homepage         = 'https://www.wagawin.com'
  s.license          = { :type => 'Copyright', :text => 'Copyright 2017, Wagawin GmbH, all rights reserved' }
  s.author           = { 'Wagawin GmbH' => 'publisher@wagawin.com' }
  s.source           = { :git => 'https://github.com/Wagawin/wagawin-sdk-ios.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'

  s.source_files = 'WagawinSDK/Framework/**/*.h'
  s.vendored_libraries = 'WagawinSDK/Framework/**/*.a'
  s.public_header_files = 'WagawinSDK/Framework/**/*.h'

  s.resources = ['WagawinSDK/Assets/**/*.bundle']
  s.frameworks = 'UIKit', 'SystemConfiguration', 'CoreTelephony'
  s.libraries = 'z'

end
