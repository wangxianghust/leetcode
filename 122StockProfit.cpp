/* 求组大利润，可以多次买入多次卖，但是必须进行完一次买卖可以进行下一次
 * Solution:只要关注升序序列即可。ret += max(0, price[i]-price[i-1]);
 */
