## 各目录说明

- common目录是必须的, 其中51config.h为配置文件
- include目录是source下相应源文件的头文件
- output是输出目录, 在keil中可以设置hex输出到此,当然也可以不这样
- project是工程目录, 建议把工程建到这个文件夹下
- source目录下是所有源文件

##　使用说明  
  **各模块api请参考对应的include目录下的头文件**

## 注意
- at24c02(EEPROM) 还未测试, 欢迎测试, 并提交结果. 其他均由本人进行过测试, 并在实际中使用过, 当然也欢迎提交bug
- 欢迎以同样思路封装模块代码, 并提交上来, 请尽量尊重本工程代码的风格

## 其他

### 去除函数未被调用的警告

1. Options -> Device -> √Use Extended Linker(LX51)instead of BL51
2. Options -> LX51 Misc -> Misc controls -> 填入REMOVEUNUSED 
