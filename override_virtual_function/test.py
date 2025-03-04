import sys
import os

# 获取当前文件的绝对路径
current_dir = os.path.dirname(os.path.abspath(__file__))
# 要添加的路径
new_path = os.path.join(current_dir, "build")

# 将路径添加到 sys.path
sys.path.append(new_path)

from example import Animal, Dog

# 使用 C++ 的 Dog 类
d = Dog()

# 在 Python 中继承 Animal 并重载 go 方法
class Cat(Animal):
    def go(self, n_times):
        return "meow! " * n_times

c = Cat()

print(c.go(11))
