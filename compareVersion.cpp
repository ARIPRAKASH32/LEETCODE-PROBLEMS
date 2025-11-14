#include <string>
#include <optional>
using namespace std;

// Robust on-the-fly version comparison
// Returns -1 if version1 < version2, 1 if version1 > version2, 0 if equal
class Solution {
public:
    int compareVersion(const string& version1, const string& version2) {
        auto nextToken = [](const string& s, size_t& pos) -> optional<int> {
            if (pos >= s.size()) return {};
            size_t start = pos;
            // Move to the next dot or end
            while (pos < s.size() && s[pos] != '.') ++pos;

            // If there was a dot but no digits before it (empty token)
            if (start == pos) return {};

            int val = stoi(s.substr(start, pos - start));

            // Skip the dot if present
            if (pos < s.size() && s[pos] == '.') ++pos;
            return val;
        };

        size_t p = 0, q = 0;
        while (p < version1.size() || q < version2.size()) {
            auto a = nextToken(version1, p);
            auto b = nextToken(version2, q);
            int va = a ? *a : 0;
            int vb = b ? *b : 0;

            if (va < vb) return -1;
            if (va > vb) return 1;
            // continue if equal
        }
        return 0;
    }
};


