# AutoIncrementVersion
Tự động tăng version cho các project VC++
# Hướng dẫn
* Đặt chương trình AutoIncrementVersion.exe vào thư mục C:\Windows
* Thêm Version vào Project như bình thường, bằng cách nhấn phải chuột vào Project chọn Add\Resource... Chọn tiếp thêm Version. Tuy nhiên ta sẽ không cần nhập gì cả và đóng lại. Bởi những nội dung này sẽ được định nghĩa cố định và tự động theo file resource.h
* Đặt các định nghĩa vào file resource.h trong project, ta nên đặt theo file resource.h mẫu ở đây.
* Mở source code file .rc, bằng cách nhấn chuột phải chọn View Code. Tìm đến nội dung phần Version và sửa thông tin theo các định nghĩa ở file resource.h
* Tiếp theo, ta sẽ cho chương trình chạy tăng version tự động trước khi build. Ta nhấn phải chuột vào Project chọn Properties, chọn Build Events\Pre-Build Event và nhập vào nội dung sau:
  * Command line: AutoIncrementVersion --build $(ProjectDir)  
  * Description: Auto increment version
* Build project để xem kết quả
* Ta nên gỡ bỏ file resource.h khởi project (chỉ gỡ mà không xóa) và chỉ định cho git bỏ qua nó.
