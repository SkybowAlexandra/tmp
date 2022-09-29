#C++
#编译器
CROSS_COMPILE 	?= g++-11.2
#目标
TARGET		  	?= example.out#<在这里改变目标>

CC				:=	$(CROSS_COMPILE)#编译器

#指定头文件目录<在这里添加新增的头文件>
INCUDIRS		:=	include 
#指定源码目录的定义<在这里添加新增的源文件>
SRCDIRS			:=	project	\
					src 
#Mkafile头文件路径，需要-I，我们编译源码的时候需要指定头文件路径
INCLUDE			:=	$(patsubst %, -I %,$(INCUDIRS))

#wildcard统配dir下的所有.c .cpp文件，最后放到CPPFILES中
CPPFILES		:=	$(foreach dir, $(SRCDIRS),$(wildcard $(dir)/*.cpp))
CFILES	 		:=  $(foreach dir, $(SRCDIRS),$(wildcard $(dir)/*.c))

#所有的.o文件放在obj里
CPPFILENDIR		:=$(notdir $(CPPFILES))  #notdir取消掉.cpp路径名
CFILENDIR		:=$(notdir $(CFILES))	#notdir取消掉.c路径名

CPPOBJS			:=	$(patsubst %, obj/%, $(CPPFILENDIR:.cpp=.o))
COBJS           :=  $(patsubst %, obj/%, $(CFILENDIR:.c=.o))
#OBJS就是所有的.o文件
OBJS			:=	$(CPPOBJS)
OBJS 			+= $(COBJS)
#如果在当前目录找不到文件，就在VPATH中找文件
VPATH			:=	$(SRCDIRS)

#线程库
PTHREAD = -lpthread
#libevent库
EVENT = -levent
#mysql库
LIBMYSQL = -lmysqlpp
#zlib库
ZLIB = -lz
#编译选项
FLAGS			:= -g -Wall -std=c++17 -fpermissive

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ -g -Wall
#将所有的.c和.cpp文件编译成.o文件并且存到obj文件夹下
$(CPPOBJS) : obj/%.o : %.cpp
	$(CC) $(FLAGS) -c $(INCLUDE) -o $@ $<
$(COBJS) : obj/%.o : %.c
	$(CC) $(FLAGS) -c $(INCLUDE) -o $@ $<

	
.PHONY:clean
#清理工程
clean:
	rm -rf $(TARGET) $(OBJS)
wclean:
	rm -rf *.exe *.obj

#打印结果
print:
	@echo				"执行过程如下:"
	@echo INCLUDE		= 	$(INCLUDE)
	@echo CPPFILES		= 	$(CPPFILES)
	@echo CFILES		=   $(FILES)
	@echo CPPFILENDIR	= 	$(CPPFILENDIR)
	@echo CFILENDIR 	=   $(CFILENDIR)
	@echo CPPOBJS		= 	$(CPPOBJS)
	@echo COBJS 		=   $(COBJS)
	@echo OBJS			= 	$(OBJS)
