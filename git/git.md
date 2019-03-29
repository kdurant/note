# 分支命名
1. feature/
2. hotfix/
3. realease/

# 子模块使用
## 添加子模块
在顶级项目的目录里添加子模块
```shell
git submodule add module_addr
cd submodule-project
git submodule init
git submodule update 
```

## 更新子模块
1. 进入子模块的目录，子模块和正常木块没有什么两样，按照正常操作即可
2. 子模块提交后，上一级模块再提交

## 删除子模块
```shell
# 逆初始化模块，其中{MOD_NAME}为模块目录，执行后可发现模块目录被清空
git submodule deinit {MOD_NAME} 
# 删除.gitmodules中记录的模块信息（--cached选项清除.git/modules中的缓存）
git rm --cached {MOD_NAME} 
# 提交更改到代码库，可观察到'.gitmodules'内容发生变更
git commit -am "Remove a submodule." 
```

# commit写法
用于说明 commit 的类别，只允许使用下面7个标识。

    init：(:tada:)项目初始化（用于项目初始化或其他某种行为的开始描述，不影响代码）
    feat：(:sparkles:)新功能
    fix：(:bug:)修补bug
    docs：(:memo:)文档（documentation）
    opt：(:zap:)优化和改善，比如弹窗进行确认提示等相关的，不会改动逻辑和具体功能等
    style： (:art:)格式（不影响代码运行的变动）
    refactor：(:recycle:)重构（即不是新增功能，也不是修改bug的代码变动）
    test：(:white_check_mark:)增加测试
    save：单纯地保存记录
    other：用于难以分类的类别（不建议使用，但一些如删除不必要的文件，更新.ignore之类的可以使用）
    bookmark: (:bookmark:) 发行/版本标签
    linter: (:rotating_light:) 移除 linter 警告

emoji                                   | emoji 代码                   | commit 说明
:--------                               | :--------                    | :--------
:tada: (庆祝)                           | `:tada:`                     | 初次提交
:sparkles: (火花)                       | `:sparkles:`                 | 引入新功能
:bookmark: (书签)                       | `:bookmark:`                 | 发行/版本标签
:bug: (bug)                             | `:bug:`                      | 修复 bug
:ambulance: (急救车)                    | `:ambulance:`                | 重要补丁
:globe_with_meridians: (地球)           | `:globe_with_meridians:`     | 国际化与本地化
:lipstick: (口红)                       | `:lipstick:`                 | 更新 UI 和样式文件
:rotating_light: (警车灯)               | `:rotating_light:`           | 移除 linter 警告
:wrench: (扳手)                         | `:wrench:`                   | 修改配置文件
:heavy_plus_sign: (加号)                | `:heavy_plus_sign:`          | 增加一个依赖
:heavy_minus_sign: (减号)               | `:heavy_minus_sign:`         | 减少一个依赖
:arrow_up: (上升箭头)                   | `:arrow_up:`                 | 升级依赖
:arrow_down: (下降箭头)                 | `:arrow_down:`               | 降级依赖
:zap: (闪电)<br>:racehorse: (赛马)      | `:zap:`<br>`:racehorse:`      | 提升性能
:chart_with_upwards_trend: (上升趋势图) | `:chart_with_upwards_trend:` | 添加分析或跟踪代码
:rocket: (火箭)                         | `:rocket:`                   | 部署功能
:white_check_mark: (白色复选框)         | `:white_check_mark:`         | 增加测试
:memo: (备忘录)                         | `:memo:`                     | 撰写文档
:recycle:                              | `:recycle:`                  | 重构
:hammer: (锤子)                         | `:hammer:`                   | 重大重构
:art: (调色板)                          | `:art:`                      | 改进代码结构/代码格式
:fire: (火焰)                           | `:fire:`                     | 移除代码或文件
:pencil2: (铅笔)                        | `:pencil2:`                  | 修复 typo
:construction: (施工)                   | `:construction:`               | 工作进行中
:construction_worker: (工人)            | `:construction_worker:`      | 添加 CI 构建系统
:green_heart: (绿心)                    | `:green_heart:`              | 修复 CI 构建问题
:lock: (锁)                             | `:lock:`                     | 修复安全问题
:whale: (鲸鱼)                          | `:whale:`                    | Docker 相关工作
:apple: (苹果)                          | `:apple:`                    | 修复 macOS 下的问题
:penguin: (企鹅)                        | `:penguin:`                  | 修复 Linux 下的问题
:checkered_flag: (旗帜)                 | `:checked_flag:`             | 修复 Windows 下的问题
:see_no_evil:                           | `:see_no_evil:`              | 更改.gitignore文件

# 远程仓库操作
## 修改远程仓库地址
1. 方法一
git remote 查看所有远程仓库， git remote xxx 查看指定远程仓库地址
git remote set-url origin http://192.168.100.235:9797/john/git_test.git
2. 方法二
```
git remote rm origin
git remote add origin [url]
```

## 提交新的本地分支到远程仓库
1. 切换到需要提交的分支
2. 推送本地分支到远程分支
> git push --set-upstream origin 分支名
或者
> git push origin HEAD -u
3. 以后push新分支使用：git push origin wy:wy  ？？？

## 将远程git仓库里的指定分支拉取到本地（本地不存在的分支）
> git pull origin master:wy

## 删除远程分支
> git push origin --delete <BranchName>

# rebase

假定已有commit如下：
                    M4 -> M5 -> M6 (master)
M1 -> M2 -> M3 -> 
                    D1 -> D2 -> D3 (dev)

发现需要在M2的基础上进行修改共同的文件，可以在M2上建立新的分支，修改后rebase。

具体流程
1. 在M2建立新分支`test`
2. 切换到新分支
3. 修改代码并提交
4. 切换到master分支，执行`git rebase test`
5. 切换到dev分支，执行`git rebase test`

说明：
1. 新的commit记录
                           M4 -> M5 -> M6 (master)
M1 -> M2 -> R1 -> M3 ->    
                           D1 -> D2 -> D3 (dev)

2. `以上操作建立在rebase时没有冲突的情况下`

# tag操作

## push本地tag到远程仓库
git push origin --tags

## pull远程tag到本地

## 删除远程tag
git push origin --delete tag v1.2.2

# clone 

## clone带有子模块的repo
`git clone repo_addr --recursive`