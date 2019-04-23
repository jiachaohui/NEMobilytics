
Pod::Spec.new do |s|

  s.name         = "NEMobilytics"
  s.version      = "2.2.1-snapshot1"
  s.summary      = "NEMobilytics is an iOS tracking tools for Netease."

  s.description  = <<-DESC
                NEMobilyticsis an iOS tracking tools for NetEase Internal Usage.
                   DESC

  s.homepage     = "https://hubble.netease.com/"
  s.license      = { :type => "MIT", :file => "LICENSE"}
  s.author             = { "jiachaohui" => "jiachaohui@corp.netease.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/jiachaohui/NEMobilytics.git", :tag => "#{s.version}" }

  s.vendored_frameworks = 'NEMobilytics.framework'

end
