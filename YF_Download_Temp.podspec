
Pod::Spec.new do |spec|

  spec.name         = "YF_Download_Temp"
  spec.version      = "1.0.1"
  spec.summary      = "下载工具"

  spec.description  = <<-DESC
  iOS公会系统功能库
                   DESC

  spec.homepage     = "https://github.com/leonard-li/YF_Download_Temp.git"


  spec.license      = { :type => "MIT", :file => "LICENSE" }

  spec.author             = { "leonard.li" => "495145872@qq.com" }

  spec.ios.deployment_target = "9.0"

  spec.source       = { :git => "https://github.com/leonard-li/YF_Download_Temp.git", :tag => spec.version }

  spec.vendored_frameworks = 'YFDownloader.framework'

  spec.requires_arc = true

  spec.dependency "YF_Core", '>= 1.5.9.3'
  spec.resource_bundles = {
    'YF_DownloadResources' => ['Resources/PrivacyInfo.xcprivacy']
  }

end
