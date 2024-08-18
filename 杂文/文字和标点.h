/*本文档的内容：
  为了适应张家馨的习惯，增强程序的通用性和可移植性，同时也便于阅读与写作，张家馨使用typedef声明了一些新的类型名，用来定义变量；使用#define简单地替换了一些字符串；还定义了一些新的操作。
  这将在预编译时起作用。

 *要写成这样子：
  
  甲是基本整数;       // int 甲
  乙是字符;          // char 乙
  丙是基本整数指针;   // int* 丙
  丁是短整数数组;     // short int[] 丁
  戊是基本整数函数;   // int 戊()

  是的作用是对调前后文字的顺序。（暂时无法实现这个功能。）

 *标点符号替换

  ;改为。
  (改为（
  )改为）
  ,改为，
  
  *作者介绍
   张家馨，涿鹿县界牌梁人，生于一九九二年。
*/

#pragma once

/*+----------------------------------------------------------------------------------------+*/
/*|   					                第一部分 新的类型		                               |*/
/*+----------------------------------------------------------------------------------------+*/
/*
				|基本整数(int)
				|短整数(short int)
				|长整数(long int)
			|整形类型|*双长整数(long long int)
			|	|字符(char)
			|	|*布尔数(bool)
		|基本类型|
		|	|	|短小数(float)
		|	|浮点类型|长小数(double)
		|	|	|复数小数(float_complex,double_complex,long long_complex)
		|
	数据类型|枚举类型(enum)
		|空类型(void)
		|
		|	|指针(*)
		|	|数组([])
		|派生类型|结构体(struct)
			|共同体(union)
			|函数

			图1 C语言允许使用的类型（图中有*的是C99所增加的）
*/

typedef int			整数;
typedef short int		短整数;
typedef long int		长整数;
typedef long long int		双长整数;
typedef	char			字符;
typedef bool			布尔;
typedef float			短小数;
typedef double			长小数;
typedef float_complex		短复数小数;
typedef double_complex		长复数小数;
typedef long long_complex	双长复数小数;
typedef void 			空类型;

typedef struct
{
	char	红色;
	char	绿色;
	char	蓝色;
}颜色;

typedef struct
{
	char		红色;
	char		绿色;
	char		蓝色;
	short int	横坐标;
	short int	纵坐标;
}点;

typedef (const char) 文件名;

/*+----------------------------------------------------------------------------------------+*/
/*|				                    	第二部分 替换的文字     			            	   |*/
/*+----------------------------------------------------------------------------------------+*/
/*
        auto            enum            restrict        unsigned
		break           extern          return          void
		case            float           short           volatile
		char            for             signed          while
		const           goto            sizeof          _Bool
		continue        if              static          _Complex
		default         inline          struct          _Imaginary
		do              int             switch          
		double          long            typedef         
		else            register        union
		
		                  图2 C语言的关键字（采用C99标准）

  其中，double、extern、float、inline、long、restrict、short、signed、static、unsigned、volatile、_Bool、_Complex、_Imaginary因为在第一部分已有定义，或用得少，没有替换成自己习惯的文字。
*/
#define 引用		include
#define 规定		define
#define 如果规定          ifdef
#define 如果没有规定       ifndef
#define 取消规定          undef
#define 如果              if
#define 不然              elif
#define 否则              else
#define 结束              endif
#define 出错              error
#define 编译一次          (pragma once)
#define 编译消息          (pragma message)
#define 编译警告          (pragma warning)
#define 编译注释          (pragma comment)
#define 编译结束          (pragma hdrstop)
#define 编译资源          (pragma resource)

#define 自动              auto
#define 中止              break
#define 情形              case
#define 固定              const
#define 继续              continue
#define 默认              default
#define 执行              do
#ifndef 否则              
#define 否则              else
#endif
#define 列举              enum
//#define extern     
#define 对于              for
#define 跳转              goto
#ifndef 如果
#define 如果              if
#endif
//#define inline
#define 登记              register
//#define restrict
#define 等于              return
//#define signed
#define 尺寸              sizeof
//#define static
#define 结构              struct
#define 切换              switch
#define 别名              typedef
#define 联合              union
//#define volatile
#define 正当              while
//#define _Bool
//#define _Complex
//#define _Imaginary

#define 主函数		main

#define 正确		1
#define 错误		0
#define 成功		1
#define 失败		0

/*+----------------------------------------------------------------------------------------+*/
/*|                                     第三部分 新的操作                                     |*/
/*+----------------------------------------------------------------------------------------+*/
#define 最大数(a,b) (((a)>(b))?(a):(b))
#define 最小数(a,b) (((a)<(b))?(a):(b))

/*+----------------------------------------------------------------------------------------+*/
/*|                                     第四部分 标点符号                                     |*/
/*+----------------------------------------------------------------------------------------+*/
#define 指针 *
#define , ，
#define ; 。
#define ( （
#define ) ）



