/*
 * IDENTIFICATION:
 * stub generated Fri Jan  8 14:32:21 2021
 * with a MiG generated by bootstrap_cmds-117
 * OPTIONS: 
 *	KernelUser
 */
#define	__MIG_check__Reply__resource_notify_subsystem__ 1

#include "resource_notify.h"

/* TODO: #include <mach/mach.h> */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
extern void mach_msg_destroy(mach_msg_header_t *);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#ifndef	mig_internal
#define	mig_internal	static __inline__
#endif	/* mig_internal */

#ifndef	mig_external
#define mig_external
#endif	/* mig_external */

#if	!defined(__MigTypeCheck) && defined(TypeCheck)
#define	__MigTypeCheck		TypeCheck	/* Legacy setting */
#endif	/* !defined(__MigTypeCheck) */

#if	!defined(__MigKernelSpecificCode) && defined(_MIG_KERNEL_SPECIFIC_CODE_)
#define	__MigKernelSpecificCode	_MIG_KERNEL_SPECIFIC_CODE_	/* Legacy setting */
#endif	/* !defined(__MigKernelSpecificCode) */

#ifndef	LimitCheck
#define	LimitCheck 0
#endif	/* LimitCheck */

#ifndef	min
#define	min(a,b)  ( ((a) < (b))? (a): (b) )
#endif	/* min */

#if !defined(_WALIGN_)
#define _WALIGN_(x) (((x) + 3) & ~3)
#endif /* !defined(_WALIGN_) */

#if !defined(_WALIGNSZ_)
#define _WALIGNSZ_(x) _WALIGN_(sizeof(x))
#endif /* !defined(_WALIGNSZ_) */

#ifndef	UseStaticTemplates
#define	UseStaticTemplates	0
#endif	/* UseStaticTemplates */

#ifndef MIG_SERVER_ROUTINE
#define MIG_SERVER_ROUTINE
#endif

#ifndef	__MachMsgErrorWithTimeout
#define	__MachMsgErrorWithTimeout(_R_) { \
	switch (_R_) { \
	case MACH_SEND_INVALID_DATA: \
	case MACH_SEND_INVALID_DEST: \
	case MACH_SEND_INVALID_HEADER: \
		mig_put_reply_port(InP->Head.msgh_reply_port); \
		break; \
	case MACH_SEND_TIMED_OUT: \
	case MACH_RCV_TIMED_OUT: \
	default: \
		mig_dealloc_reply_port(InP->Head.msgh_reply_port); \
	} \
}
#endif	/* __MachMsgErrorWithTimeout */

#ifndef	__MachMsgErrorWithoutTimeout
#define	__MachMsgErrorWithoutTimeout(_R_) { \
	switch (_R_) { \
	case MACH_SEND_INVALID_DATA: \
	case MACH_SEND_INVALID_DEST: \
	case MACH_SEND_INVALID_HEADER: \
		mig_put_reply_port(InP->Head.msgh_reply_port); \
		break; \
	default: \
		mig_dealloc_reply_port(InP->Head.msgh_reply_port); \
	} \
}
#endif	/* __MachMsgErrorWithoutTimeout */

#ifndef	__DeclareSendRpc
#define	__DeclareSendRpc(_NUM_, _NAME_)
#endif	/* __DeclareSendRpc */

#ifndef	__BeforeSendRpc
#define	__BeforeSendRpc(_NUM_, _NAME_)
#endif	/* __BeforeSendRpc */

#ifndef	__AfterSendRpc
#define	__AfterSendRpc(_NUM_, _NAME_)
#endif	/* __AfterSendRpc */

#ifndef	__DeclareSendSimple
#define	__DeclareSendSimple(_NUM_, _NAME_)
#endif	/* __DeclareSendSimple */

#ifndef	__BeforeSendSimple
#define	__BeforeSendSimple(_NUM_, _NAME_)
#endif	/* __BeforeSendSimple */

#ifndef	__AfterSendSimple
#define	__AfterSendSimple(_NUM_, _NAME_)
#endif	/* __AfterSendSimple */

#define msgh_request_port	msgh_remote_port
#define msgh_reply_port		msgh_local_port



/* SimpleRoutine cpu_usage_violation */
mig_external kern_return_t send_cpu_usage_violation
(
	mach_port_t receiver,
	proc_name_t procname,
	int pid,
	posix_path_t killed_proc_path,
	mach_timespec_t timestamp,
	int64_t observed_cpu_nsecs,
	int64_t observation_nsecs,
	int64_t cpu_nsecs_allowed,
	int64_t limit_window_nsecs,
	resource_notify_flags_t flags
)
{

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		proc_name_t procname;
		char procnamePad[3];
		int pid;
		posix_path_t killed_proc_path;
		mach_timespec_t timestamp;
		int64_t observed_cpu_nsecs;
		int64_t observation_nsecs;
		int64_t cpu_nsecs_allowed;
		int64_t limit_window_nsecs;
		resource_notify_flags_t flags;
	} Request __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
	} Mess;

	Request *InP = &Mess.In;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__cpu_usage_violation_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__cpu_usage_violation_t__defined */

	__DeclareSendSimple(827800, "cpu_usage_violation")

	InP->NDR = NDR_record;

	{   typedef struct { char data[33]; } *sp;
	    * (sp) InP->procname = * (sp) procname;
	}
	    for (int i = 0; i < 3; i++)
		    InP->procnamePad[i] = 0;

	InP->pid = pid;

	{   typedef struct { char data[512]; } *sp;
	    * (sp) InP->killed_proc_path = * (sp) killed_proc_path;
	}

	InP->timestamp = timestamp;

	InP->observed_cpu_nsecs = observed_cpu_nsecs;

	InP->observation_nsecs = observation_nsecs;

	InP->cpu_nsecs_allowed = cpu_nsecs_allowed;

	InP->limit_window_nsecs = limit_window_nsecs;

	InP->flags = flags;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, 0);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = receiver;
	InP->Head.msgh_reply_port = MACH_PORT_NULL;
	InP->Head.msgh_id = 827800;
	InP->Head.msgh_reserved = 0;

	__BeforeSendSimple(827800, "cpu_usage_violation")
#if	__MigKernelSpecificCode
	msg_result = mach_msg_send_from_kernel(&InP->Head, (mach_msg_size_t)sizeof(Request));
#else
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), 0, MACH_PORT_NULL, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
#endif /* __MigKernelSpecificCode */
	__AfterSendSimple(827800, "cpu_usage_violation")
	return msg_result;
}

/* SimpleRoutine cpu_wakes_violation */
mig_external kern_return_t send_cpu_wakes_violation
(
	mach_port_t receiver,
	proc_name_t procname,
	int pid,
	posix_path_t killed_proc_path,
	mach_timespec_t timestamp,
	int64_t observed_cpu_wakes,
	int64_t observation_nsecs,
	int64_t cpu_wakes_allowed,
	int64_t limit_window_nsecs,
	resource_notify_flags_t flags
)
{

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		proc_name_t procname;
		char procnamePad[3];
		int pid;
		posix_path_t killed_proc_path;
		mach_timespec_t timestamp;
		int64_t observed_cpu_wakes;
		int64_t observation_nsecs;
		int64_t cpu_wakes_allowed;
		int64_t limit_window_nsecs;
		resource_notify_flags_t flags;
	} Request __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
	} Mess;

	Request *InP = &Mess.In;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__cpu_wakes_violation_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__cpu_wakes_violation_t__defined */

	__DeclareSendSimple(827801, "cpu_wakes_violation")

	InP->NDR = NDR_record;

	{   typedef struct { char data[33]; } *sp;
	    * (sp) InP->procname = * (sp) procname;
	}
	    for (int i = 0; i < 3; i++)
		    InP->procnamePad[i] = 0;

	InP->pid = pid;

	{   typedef struct { char data[512]; } *sp;
	    * (sp) InP->killed_proc_path = * (sp) killed_proc_path;
	}

	InP->timestamp = timestamp;

	InP->observed_cpu_wakes = observed_cpu_wakes;

	InP->observation_nsecs = observation_nsecs;

	InP->cpu_wakes_allowed = cpu_wakes_allowed;

	InP->limit_window_nsecs = limit_window_nsecs;

	InP->flags = flags;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, 0);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = receiver;
	InP->Head.msgh_reply_port = MACH_PORT_NULL;
	InP->Head.msgh_id = 827801;
	InP->Head.msgh_reserved = 0;

	__BeforeSendSimple(827801, "cpu_wakes_violation")
#if	__MigKernelSpecificCode
	msg_result = mach_msg_send_from_kernel(&InP->Head, (mach_msg_size_t)sizeof(Request));
#else
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), 0, MACH_PORT_NULL, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
#endif /* __MigKernelSpecificCode */
	__AfterSendSimple(827801, "cpu_wakes_violation")
	return msg_result;
}

/* SimpleRoutine disk_writes_violation */
mig_external kern_return_t send_disk_writes_violation
(
	mach_port_t receiver,
	proc_name_t procname,
	int pid,
	posix_path_t killed_proc_path,
	mach_timespec_t timestamp,
	int64_t observed_bytes_dirtied,
	int64_t observation_nsecs,
	int64_t bytes_dirtied_allowed,
	int64_t limit_window_nsecs,
	resource_notify_flags_t flags
)
{

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		proc_name_t procname;
		char procnamePad[3];
		int pid;
		posix_path_t killed_proc_path;
		mach_timespec_t timestamp;
		int64_t observed_bytes_dirtied;
		int64_t observation_nsecs;
		int64_t bytes_dirtied_allowed;
		int64_t limit_window_nsecs;
		resource_notify_flags_t flags;
	} Request __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
	/*
	 * typedef struct {
	 * 	mach_msg_header_t Head;
	 * 	NDR_record_t NDR;
	 * 	kern_return_t RetCode;
	 * } mig_reply_error_t;
	 */

	union {
		Request In;
	} Mess;

	Request *InP = &Mess.In;

	mach_msg_return_t msg_result;

#ifdef	__MIG_check__Reply__disk_writes_violation_t__defined
	kern_return_t check_result;
#endif	/* __MIG_check__Reply__disk_writes_violation_t__defined */

	__DeclareSendSimple(827802, "disk_writes_violation")

	InP->NDR = NDR_record;

	{   typedef struct { char data[33]; } *sp;
	    * (sp) InP->procname = * (sp) procname;
	}
	    for (int i = 0; i < 3; i++)
		    InP->procnamePad[i] = 0;

	InP->pid = pid;

	{   typedef struct { char data[512]; } *sp;
	    * (sp) InP->killed_proc_path = * (sp) killed_proc_path;
	}

	InP->timestamp = timestamp;

	InP->observed_bytes_dirtied = observed_bytes_dirtied;

	InP->observation_nsecs = observation_nsecs;

	InP->bytes_dirtied_allowed = bytes_dirtied_allowed;

	InP->limit_window_nsecs = limit_window_nsecs;

	InP->flags = flags;

	InP->Head.msgh_bits =
		MACH_MSGH_BITS(19, 0);
	/* msgh_size passed as argument */
	InP->Head.msgh_request_port = receiver;
	InP->Head.msgh_reply_port = MACH_PORT_NULL;
	InP->Head.msgh_id = 827802;
	InP->Head.msgh_reserved = 0;

	__BeforeSendSimple(827802, "disk_writes_violation")
#if	__MigKernelSpecificCode
	msg_result = mach_msg_send_from_kernel(&InP->Head, (mach_msg_size_t)sizeof(Request));
#else
	msg_result = mach_msg(&InP->Head, MACH_SEND_MSG|MACH_MSG_OPTION_NONE, (mach_msg_size_t)sizeof(Request), 0, MACH_PORT_NULL, MACH_MSG_TIMEOUT_NONE, MACH_PORT_NULL);
#endif /* __MigKernelSpecificCode */
	__AfterSendSimple(827802, "disk_writes_violation")
	return msg_result;
}
