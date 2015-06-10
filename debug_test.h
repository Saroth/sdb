#ifndef __DEBUG_TEST_H__
#define __DEBUG_TEST_H__

/** \brief 测试列表结构体 */
typedef struct {
    char * info;                        //!< 列表项信息
    void * param;                       //!< 测试函数参数
    int (*func)(void *);                //!< 测试函数
}DBG_TESTLIST_T;

/**
 * \brief       测试列表控制
 * \param       list            列表数组
 * \return      0               Success
 */
int dbg_testlist(DBG_TESTLIST_T * list, int size);

#endif /* __DEBUG_TEST_H__ */

