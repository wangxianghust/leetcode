/* 任意给定一个复杂的URL，将其映射为http://tinyurl.com/4e9iAk形式，也就是一个url映射为6个字符组合
 * 字符集包括26*2个字母，10个数字。
 * 同时要求可以将字符映射成URL
 * Solution:因为要一一映射，解决方案就是计数，先查重，第一次出现的话计数器加一。现在共有62个字符，也就是可以自制一个
 * 62进制的计数器。共有62^6个。现在考虑全部是6个的组合，需要两个map
 * map<string long, string short>(映射存储)   map<int id, string long>(查询) 其中short 是 id 的62进制转化为string，short和id可以互逆转化
 *
 * 其他分析：这是工业界的常用做法，最后数据存在数据库中如分布式的HBase，用count进行索引。但是问题也是很多的，如用户可以发现
 * 其实第几个不重复的url,这个信息我不想让用户知道。其中能够映射的数量也是有限的；
 * 查询性能和unordered_map相关(不过一般效率较高)等等吧。
 */

#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(book.find(longUrl) != book.end()) return book[longUrl];
        ++id;
        string short_url = Int2ShortUrl(id);
        book[longUrl] = short_url;
        query[id] = longUrl;
        return short_url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
         long _id = shortUrl2Int(shortUrl);
         if(_id > id) return ""; //this short url is not existed.
         if(query.find(_id) != query.end())return query[_id];
         else return "";
    }

    Solution(){
        //Initialize it to 0123..abc..xyzABC..XYZ
        id = 0;
        dict.resize(62);
        int i = 0;
        for( ; i<10; ++i)dict[i] = '0' + i;
        for( ; i<36; ++i)dict[i] = 'a' + (i-10);
        for( ; i<62; ++i)dict[i] = 'A' + (i-36);
    }

private:
    long shortUrl2Int(string url){
        long ret(0);
        int size(url.size());
        for(int i=0; i<size; ++i){
            ret = ret*62 + (int)dict.find(url[i]);
        }
        return ret;
    }
    
    string Int2ShortUrl(long _id){
        string url;
        while(_id){
            url += dict[_id%62];
            _id /= 62;
        }
        while(url.size() < 6){
            url = '0' + url;
        }
        return url;
    }

private:
    unordered_map<string, string> book; // map longUrl to shortUrl; for duplicate insert, return short directly.
    unordered_map<long, string> query; // map id to longUrl; for query the long.
    string dict;
    long id;
};

int main(){
    Solution Sol;
    string url_1 = "https://leetcode.com/problems/encode-and-decode-tinyurl/#/solutions";
    string url_2 = "www.hust.edu.cn";
    string url_3 = "https://leetcode.com/problems/encode-and-decode-tinyurl/#/solutions";
    cout << Sol.encode(url_1) << endl;
    cout << Sol.encode(url_2) << endl;
    cout << Sol.encode(url_3) << endl;
    cout << Sol.decode( Sol.encode(url_1) ) << endl;
    cout << Sol.decode( Sol.encode(url_2) ) << endl;
    cout << Sol.decode( Sol.encode(url_3) ) << endl;

}
