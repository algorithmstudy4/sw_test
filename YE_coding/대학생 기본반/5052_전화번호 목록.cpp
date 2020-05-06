// 백준 https://www.acmicpc.net/problem/5052
// 전화번호 목록
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int change(char c) {
	return c - '0';
}

struct Trie {
	Trie* children[10];
	bool terminal;

	Trie() : terminal(false) {
		memset(children, 0, sizeof(children));
	}

	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') {
			terminal = true;
		}
		else {
			int next = change(*key);
			if (!children[next]) {
				children[next] = new Trie();
			}
			children[next]->insert(key + 1);
		}
	}

	bool isVaild(const char* key) {
		if (*key == '\0') return true;
		if (terminal) return false;

		int next = change(*key);
		return children[next]->isVaild(key + 1);
	}
};

int main() {
	int T, N;
	char str[10000][11];
	bool flag;

	scanf("%d", &T);

	while (T--) {
		Trie* root = new Trie();
		flag = true;

		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s", &str[i]);
			root->insert(str[i]);
		}

		for (int i = 0; i < N; i++) {
			if (!root->isVaild(str[i])) {
				flag = false;
				break;
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");

		delete root;
	}

	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int change(char c) {
	return c - '0';
}

struct Trie {
	Trie* children[10];
	bool terminal;

	Trie() : terminal(false) {
		memset(children, 0, sizeof(children));
	}

	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') {
			terminal = true;
		}
		else {
			int next = change(*key);
			if (!children[next]) {
				children[next] = new Trie();
			}
			children[next]->insert(key + 1);
		}
	}

	bool isVaild(const char* key) {
		if (*key == '\0') return true;
		if (terminal) return false;

		int next = change(*key);
		return children[next]->isVaild(key + 1);
	}
};

int main() {
	int T, N;
	char str[10000][11];
	bool flag;

	scanf("%d", &T);

	while (T--) {
		Trie* root = new Trie();
		flag = true;

		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s", &str[i]);
			root->insert(str[i]);
		}

		for (int i = 0; i < N; i++) {
			if (!root->isVaild(str[i])) {
				flag = false;
				break;
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");

		delete root;
	}

	return 0;
}
