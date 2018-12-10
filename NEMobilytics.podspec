
Pod::Spec.new do |s|

  s.name         = "NEMobilytics"
  s.version      = "2.1.17"
  s.summary      = "A short description of NEMobilytics."

  s.description  = <<-DESC
                Mobilytics for NetEase Internal Usage.
                   DESC

  s.homepage     = "https://hubble.netease.com/"
  s.license      = { :type => "MIT"}
  s.author             = { "jiachaohui" => "jiachaohui@corp.netease.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "http://EXAMPLE/NEMobilytics.git", :tag => "#{s.version}" }

  s.vendored_frameworks = 'NEMobilytics.framework'

end
