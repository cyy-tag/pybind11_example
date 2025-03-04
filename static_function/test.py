import sys
import os

# 获取当前文件的绝对路径
current_dir = os.path.dirname(os.path.abspath(__file__))
# 要添加的路径
new_path = os.path.join(current_dir, "build")

# 将路径添加到 sys.path
sys.path.append(new_path)

from example import MyClass

# 调用类静态方法
print(MyClass.static_method(5, 4))
