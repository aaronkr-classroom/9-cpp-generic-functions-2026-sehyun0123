#pragma once

#ifndef GUARD_my_algs_T_h
#define GUARD_my_algs_t_h

#include<cctype>
#include<string>
#include<algorithm>

using namespace std;

//최대값
template<class T>
T max(const T& left, const T& right) {
	return left > right ? left : right;
}
//최소값
template<class T>
T min(const T& left, const T& right) {
	return left < right ? left : right;
}
//같은 값
template <class T>
bool equals(const T& left, const T& right) {
	return left == right ? true : false;
}

//다른 값
template <class T>
bool not_equals(const T& left, const T& right) {
	//return left != right ? false : true;
	//return left == right ? true : false;
	return !equals(left, right);
}
//알 수 없는 자료형의 벡터에 있는 요소 (값)을 찾기
template<class In,class X>
In find(In begin, In end, const X& x) {
	//끝까지 안 가서 값도 찾지 못했을 때
	while (begin != end && *begin != x) {
		++begin;
	}

	return begin;
}

//사본 만들기
template <class In, class Out>
Out copy(In begin, In end, Out dest) {
	//첫 요소부터 끝까지 모든
	//begin 반복자의 있는 요소를 dset 반복자로 복사하기
	while (begin != end) {
		*dest++ = *begin++;
	}

	return dest;
}

//덮어쓰기
template <class For, class X>
void replace(For beg, For end, const X& x, const X& y) {
	while (beg != end) {
		if (*beg == x) {
			*beg = y;
		}
		++beg;
	}
}

//역방향으로 재저장하기
template<class Bi>
void reverse(Bi begin, Bi end) {
	while (begin != end) {
		--end;
		if (begin != end) {
			swap(*begin++, *end);
		}
	}
}

//이진법 탐색
template <class Oct, class X>
bool binary_search(Oct begin, Oct end, const X& x) {
	while (begin < end) {
		//범위의 중간지점 찾기
		Oct mid = begin + (end - begin) / 2;

		//중간 지점을 기준으로 어는 부분이 x를
		//포함하는지 확인하고 해당 부분에만
		//탐색을 계속 진행
		if (x < *mid)	end = mid;
		else if (*mid < x)	begin = mid + 1;
		else return true; // 이 지점에 도달하면 *mid == x
	}
	return false;
}

//인수가 공백일 때는 true , 그렇지 않을 때는 false
bool space(char c) {
	return isspace(c); // #include<cctype>
}

//인수가 공백일 때는 false, 그렇지 않을 때는 true
bool not_space(char c) {
	return !isspace(c);
}

//문자열 나누기
template<class Out>
void split(const string& str, Out os) {
	typedef string::const_iterator iter;

	iter i = str.begin();

	while (i != str.end()) {
		//선행 공백을 무시
		//지금 i위치부터 첫 번째 띄어쓰기 아닌 문자 찾기
		i = find_if(i, str.end(), not_space);

		//다음 단어의 끝을 찾음
		//while 반복할 때 항상 새로운 반복자 j를 생성
		//지금 i위치부터 첫 번째 띄어쓰기 문자 찾기
		iter j = find_if(i, str.end(), space);

		//[i,j) 범위의 문자를 복사
		if (i != str.end()) {
			*os++ = string(i, j); // 출력 스트림에서 출력
		}

		//i 반복자 위치가 j 반복자의 위치를 저장하기
		i = j;
	}


}

#endif // !GUARD_my_algs_T_h
