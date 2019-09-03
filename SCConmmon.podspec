  Pod::Spec.new do |s|
  s.name         = "SCConmmon"
  s.version      = "0.0.1"
  s.summary      = "FT test 0.0.1"
  s.description  = "FT test 0.0.1 sc"
  s.homepage     = "https://github.com/shichao666/SCCommon.git"
  s.license      = "MIT"
  s.author             = { "shichao" => "329585013@qq.com" }
  s.source       = { :git => "https://github.com/shichao666/SCCommon.git", :tag => "#{s.version}" }

  # s.source_files  = "SCCommon", "SCCommon/**/*.{h,m}"
  s.source_files = "Resurce/Base/*.{h,m}","Resurce/NetWork/*.{*}","Resurce/NetWork/*.*"
  #你的SDK路径（因为传的是静态库，这个必须要）
  s.vendored_frameworks = 'Resurce/FTFramework.framework'
  #资源文件(含bundle)
  s.resources = "Resurce/FTCommonBundle.bundle"
  #依赖库
  s.frameworks = "Foundation", "UIKit"

  #支持最小系统版本
  s.platform     = :ios, "8.0"
  #依赖的第三方，有几个写几个
  s.dependency 'AFNetworking','~> 3.2.1'
  s.dependency 'MJExtension', '~> 3.0.13'
  s.dependency 'SVProgressHUD', '~> 2.2.5'
  s.dependency 'ReactiveObjC', '~> 3.1.0'
  s.dependency 'CYLTabBarController', '~> 1.17.22'
  s.dependency 'DZNEmptyDataSet', '~> 1.8.1'
  s.dependency 'SDCycleScrollView', '~> 1.75'
# "MJExtension", "SVProgressHUD", "ReactiveObjC", "CYLTabBarController", "DZNEmptyDataSet", "SDCycleScrollView"


  #s.exclude_files = "Classes/Exclude"

  # s.public_header_files = "Classes/**/*.h"


  # ――― Resources ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  A list of resources included with the Pod. These are copied into the
  #  target bundle with a build phase script. Anything else will be cleaned.
  #  You can preserve files from being cleaned, please don't preserve
  #  non-essential files like tests, examples and documentation.
  #

  # s.resource  = "icon.png"
  # s.resources = "Resources/*.png"

  # s.preserve_paths = "FilesToSave", "MoreFilesToSave"


  # ――― Project Linking ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Link your library with frameworks, or libraries. Libraries do not include
  #  the lib prefix of their name.
  #

  # s.framework  = "SomeFramework"
  # s.frameworks = "SomeFramework", "AnotherFramework"

  # s.library   = "iconv"
  # s.libraries = "iconv", "xml2"


  # ――― Project Settings ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  If your library depends on compiler flags you can set them in the xcconfig hash
  #  where they will only apply to your library. If you depend on other Podspecs
  #  you can include multiple dependencies to ensure it works.

  # s.requires_arc = true

  # s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # s.dependency "JSONKit", "~> 1.4"

end
