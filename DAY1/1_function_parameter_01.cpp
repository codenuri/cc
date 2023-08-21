// 함수의 인자 전달에 대한 규칙들
// 
// F16 ~ F21  ( 10 page ~)
// F.16 : For "in" parameters, pass cheaply - copied types by value and others by reference to const
// F.17 : For "in-out" parameters, pass by reference to non - const
// F.18 : For "will-move-from" parameters, pass by X&& and std::move the parameter
// F.19 : For "forward" parameters, pass by TP&& and only std::forward the parameter
// F.20 : For "out" output values, prefer return values to output parameters
// F.21 : To return multiple “out” values, prefer returning a struct or tuple
// F.60 : Prefer T* over T& when “no argument” is a valid option



// day1.zip 압축 풀러 보세요.

// visual studio 사용하시는 분은 vs(visual studio) 
// 에서 day1.sln 열어 보세요

// 1. 버전 설정해야 합니다.
//    프로젝트 메뉴후 속성 메뉴 선택

// 2. 빌드 하는 법 : ctrl + F5
// => 아래 코드 한줄 추가하고 빌드해 보세요
int main() {}

// 3. 파일을 빌드에 포함/제외 하는 방법
// => 파일 선택후, 마우스 오른쪽 버튼 누르고, 속성 메뉴 선택

// 4. 다른 편집기(컴파일러)사용하시는 분은 