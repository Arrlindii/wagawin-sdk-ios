
Pod::Spec.new do |s|
  s.name             = 'WagawinSDK'
  s.version          = '1.3.4'
  s.summary          = 'The Wagawin Ad Network SDK'

  s.description      = <<-DESC
The Wagawin SDK will allow you to connect your app to the Wagawin Ad Network and display Wagawin Ads in your native iOS application.
                       DESC

  s.homepage         = 'https://www.wagawin.com'
  s.license          = { :type => 'Copyright', :text => 'Copyright 2016, Wagawin GmbH, all rights reserved' }
  s.author           = { 'Wagawin GmbH' => 'publisher@wagawin.com' }
  s.source           = { :git => 'https://github.com/Wagawin/wagawin-sdk-ios.git', :tag => s.version.to_s }

  s.ios.deployment_target = '7.1'

  s.source_files = 'WagawinSDK/Framework/**/*.h'
  s.vendored_libraries = 'WagawinSDK/Framework/**/*.a'
  s.public_header_files = 'WagawinSDK/Framework/**/*.h'

  s.resources = ['WagawinSDK/Assets/**/*.bundle']
  s.frameworks = 'UIKit', 'SystemConfiguration', 'CoreTelephony'

end
