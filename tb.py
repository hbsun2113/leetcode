#!/usr/bin/python
# coding: UTF-8
#实现定时git push流程：
# 1.建立好git仓库
# 2.1修改.git/config中url项，填入账户和密码(因为定时任务要以root环境运行，所以要提前配置密码)
# 2.2修改.git/config中user项，加入用户名和邮箱
# 3.将tb.py放入对应文件夹里
# 4.配置/Library/LaunchAgents中文件(https://my.oschina.net/jackin/blog/263024)，指定什么时候开始运行tb.py
######

import commands
import os
import sys
import time

#print '*'*20
#print os.getcwd() #假设是A执行了tb.py,则打印A的所在路径(以tb.py结尾)
#print '*'*20
#print sys.path[0] #打印tb.py的路径(不以tb.py，以tb.py的父亲的路径结尾)
#print '*'*20
#print sys.argv[0] #打印tb.py的路径,相对路径执行脚本则会返回相对路径,绝对路径执行脚本则返回绝对路径(以tb.py结尾)
try:
	print time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())),
	b=sys.path[0]
	os.chdir(b)


	#a,b=commands.getstatusoutput("pwd")
	#print a,b

	a,b=commands.getstatusoutput("python readme.py")
	if a!=0:
		print "error in python readme.py:"+b
		exit()

	a,b=commands.getstatusoutput("git add .")
	if a!=0:
		print "error in add:"+b
		exit()

	a,b=commands.getstatusoutput(''' git commit -m "nothing" ''')
	if a!=0:
		print "error in commit:"+b
		exit()

	a,b=commands.getstatusoutput("git push")
	if a!=0:
		print "error in push:"+b
		exit()

	print ":	success"
    
except Exception, e:
    print 'str(Exception):\t', str(e)+'————',