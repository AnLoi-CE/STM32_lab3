**STM32 Traffic Light Controller (FSM Based)**

📌 Giới thiệu dự án (Project Overview)
Dự án này là một hệ thống điều khiển đèn giao thông mô phỏng ngã tư, được phát triển trên vi điều khiển STM32. Mã nguồn được tổ chức theo cấu trúc module hóa, áp dụng chặt chẽ mô hình Máy trạng thái hữu hạn (FSM - Finite State Machine) để quản lý luồng hoạt động linh hoạt, kết hợp với các bộ định thời bằng phần mềm (Software Timer) để tối ưu hóa việc quản lý thời gian mà không dùng hàm delay làm nghẽn hệ thống.

⚙️ Tính năng chính (Key Features)
Dựa trên kiến trúc FSM, hệ thống hỗ trợ 3 chế độ hoạt động chính:

- Chế độ Tự động (Automatic Mode): Đèn giao thông hoạt động luân phiên theo chu kỳ thời gian định sẵn cho các hướng.

- Chế độ Chỉnh tay (Manual Mode): Cho phép can thiệp chuyển đổi trạng thái đèn giao thông thông qua nút nhấn, phục vụ điều tiết giao thông cục bộ.

- Chế độ Cài đặt (Setting Mode): Cho phép người dùng tùy chỉnh thời lượng sáng của từng đèn (Đỏ, Vàng, Xanh) và lưu lại thông số.

- Hiển thị trực quan: Sử dụng LED 7 đoạn để đếm ngược thời gian của từng pha đèn.

📂 Cấu trúc mã nguồn (Source Tree Structure)
Mã nguồn trong thư mục Core/Src được chia thành các module độc lập để dễ dàng bảo trì và phát triển:

Quản lý Trạng thái (FSM):

- fsm_automatic.c: Xử lý logic vòng lặp trạng thái đèn thông thường.

- fsm_manual.c: Xử lý logic khi người dùng điều khiển đèn bằng tay.

- fsm_setting.c: Xử lý logic cập nhật, tăng giảm giá trị thời gian và lưu cấu hình.

Thiết bị Ngoại vi & Giao diện (Peripherals & UI):

- traffic_light.c: Module cấp thấp điều khiển trực tiếp các chân GPIO kết nối với đèn LED giao thông.

- led7_segment.c: Xử lý quét và hiển thị số (thời gian đếm ngược) lên khối LED 7 đoạn.

- button.c: Xử lý tín hiệu đầu vào từ nút nhấn, bao gồm thuật toán chống dội (debounce) và nhận diện thao tác nhấn giữ/nhấn thả.

Hệ thống (System Core):

- software_timer.c: Xây dựng các timer mềm đa luồng để phục vụ đếm ngược, nhấp nháy đèn hoặc quét LED mà không dùng HAL_Delay().

- global.c: Định nghĩa các biến trạng thái toàn cục, thời lượng đèn được chia sẻ giữa các module FSM.

🚀 Hướng dẫn chạy dự án (Getting Started)
Clone repository này về máy.

Mở dự án bằng STM32CubeIDE (hoặc IDE tương ứng bạn đang dùng).

Build project và nạp firmware xuống mạch STM32 thông qua ST-Link.
