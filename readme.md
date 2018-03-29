# Usage:
#counter: 
在文件夹中```make all```就会生成四种so文件和对应的四个测试程序。
默认的锁是spinlock，直接生成libcounter.so，其余的是带锁名的so文件
测试前要先运行```export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.```，否则会找不到相应的so文件。
**使用示例：**
```
make clean
make all
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
./Counter_Spinlock_Test
```
#hash: 
在文件夹中```make all```就会生成测试程序。
默认的锁是pthread，如果要其他的锁就在HashLock.h中取消注释相应的锁并注释掉不需要的锁。
测试前要先运行```export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.```，否则会找不到相应的so文件。
#list: 
在文件夹中```make all```就会生成测试程序。
默认的锁是spinlock，如果要其他的锁就在List_Lock.h中取消注释相应的锁并注释掉不需要的锁。
测试前要先运行```export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.```，否则会找不到相应的so文件。
