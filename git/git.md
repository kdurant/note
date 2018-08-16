# 分支命名
1. feature/
2. hotfix/
3. realease/

# 子模块使用
## 添加子模块
在顶级项目的目录里添加子模块
```shell
git submodule add module_addr
```

## 更新子模块
1. 进入子模块的目录，子模块和正常木块没有什么两样，按照正常操作即可
2. 子模块提交后，上一级模块再提交

# commit写法
用于说明 commit 的类别，只允许使用下面7个标识。

    init：项目初始化（用于项目初始化或其他某种行为的开始描述，不影响代码）
    feat：新功能（feature）
    fix：修补bug
    docs：文档（documentation）
    opt：优化和改善，比如弹窗进行确认提示等相关的，不会改动逻辑和具体功能等
    style： 格式（不影响代码运行的变动）
    refactor：重构（即不是新增功能，也不是修改bug的代码变动）
    test：增加测试
    save：单纯地保存记录
    other：用于难以分类的类别（不建议使用，但一些如删除不必要的文件，更新.ignore之类的可以使用）

# 远程仓库操作
## 修改远程仓库地址
git remote 查看所有远程仓库， git remote xxx 查看指定远程仓库地址
git remote set-url origin http://192.168.100.235:9797/john/git_test.git

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
