Pod::Spec.new do |s|

  s.name         = "WagawinSDK"
  s.version      = "3.0.262"
  s.summary      = "The Wagawin Ad Network SDK"

  s.description  = <<-DESC
  The Wagawin SDK let's you connect your app to the Wagawin Ad Network and display Wagawin Ads in your native iOS application.
                   DESC

  s.homepage     = "https://www.wagawin.com"
  s.license      = "Commercial"
  s.author       = { "Wagawin GmbH" => "publisher@wagawin.com" }

  s.ios.deployment_target = "9.0"

  s.source       = { :git => "https://github.com/Wagawin/wagawin-sdk-ios.git", tag:"#{s.version}"}

  s.vendored_frameworks = "WagawinSDK.framework'


end
