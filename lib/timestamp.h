#ifndef _TIMESTAMP_H___
#define _TIMESTAMP_H___


namespace amb {

double currentTime();

/*!
 * \brief The Timestamp class provides system time and monotonic time helper functions
 * Timestamp is meant to be a singleton class.  Access through instance().
 * \code
 * double currentMonotonicTime = amb::Timestamp::instance()->currentTime();
 * double epocTimeForMonotonicTime = amb::Timestamp::instance()->epochTime(currentMonotonicTime);
 * \endcode
 */
class Timestamp {
protected:
	Timestamp();

public:

	/*!
	 * \brief currentTime
	 * \return current monotonic (steady) time in seconds.
	 */
	double currentTime();

	/*!
	 * \brief epochTime
	 * \param time monotonic time usually from currentTime()
	 * \return number of seconds.milliseconds since unix epoch
	 */
	double epochTime(double time);

	/*!
	 * \brief epochTime
	 * \return current system time in seconds since unix epoch
	 */
	double epochTime();

public:
	/*!
	 * \brief instance
	 * \return instance of Timestamp;
	 */
	static Timestamp *instance();

private:
	double startTimeEpoch;
	static Timestamp* mInstance;
};

}

#endif
