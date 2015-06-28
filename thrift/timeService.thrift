/*
时间服务
提供对时功能
*/


namespace cpp fighter.time
namespace java fighter.time

enum WEEKDAY
{
SUN=0,
MON=1,
TUE=2,
WED=3,
THU=4,
FRI=5,
SAT=6
}

/*

时间服务
*/
service timeservice 
{
/*
返回当前的时间戳
*/
  i64 time(),
  
  /*
  返回当前的时间字符串
 yyyy-mm-dd HH:MM:SS
  */
  string timeStr(),
  
  /*
 返回星期几
  */
  WEEKDAY getWeekDay()
  
}
