
Pod::Spec.new do |s|

  s.name         = "NEMobilytics"
  s.version      = "2.2.12-no-idfa"
  s.summary      = "NEMobilytics is an iOS tracking tools for Netease."

  s.description  = <<-DESC
                NEMobilyticsis an iOS tracking tools for NetEase Internal Usage.
                   DESC

  s.homepage     = "https://hubble.netease.com/"
  s.license      = { :type => "MIT", :file => "LICENSE"}
  s.author             = { "jiachaohui" => "jiachaohui@corp.netease.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/jiachaohui/NEMobilytics.git", :tag => "#{s.version}" }
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  s.vendored_frameworks = 'NEMobilytics.framework'

end
