#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct msg_q
{
	long to_mtype;
	long fm_mtype;
	char mtext[100];
}MSG_t;

int CreateMQ(key_t key);
int OpenMQ(key_t key);
long RecvMQ(int qid,long mtype, MSG_t *msgbuf);
long SendMQ(int qid,long mtype, MSG_t msgbuf);
int RemoveMQ(int qid);
