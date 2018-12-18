Pod::Spec.new do |s|

  s.name         = "WagawinSDK"
  s.version      = "RELEASE_VERSION"
  s.summary      = "The Wagawin Ad Network SDK"

  s.description  = <<-DESC
  The Wagawin SDK let's you connect your app to the Wagawin Ad Network and display Wagawin Ads in your native iOS application.
                   DESC

  s.homepage     = "https://www.wagawin.com"
  s.license      = { :type => "Commercial", :text => "Copyright 2018, Wagawin GmbH, all rights reserved" }
  s.author             = { "Wagawin GmbH" => "publisher@wagawin.com" }

  s.ios.deployment_target = "8.0"

  s.source       = { :HTTP => "https://github.com/Wagawin/wagawin-sdk-ios/archive/#{s.version}.zip"}

  s.vendored_frameworks = 'WagawinSDK.framework'


end
