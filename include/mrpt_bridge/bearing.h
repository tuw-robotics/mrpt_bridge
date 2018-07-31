#ifndef MRPT_BRIDGE_BEARING_H
#define MRPT_BRIDGE_BEARING_H

#include <stdint.h>
#include <string>

namespace std
{
template <class T>
class allocator;
}

namespace geometry_msgs
{
template <class ContainerAllocator>
struct Pose_;
typedef Pose_<std::allocator<void>> Pose;
}

namespace mrpt_msgs
{
template <class ContainerAllocator>
struct ObservationRangeBearing_;
typedef ObservationRangeBearing_<std::allocator<void>> ObservationRangeBearing;
}

namespace mrpt
{
namespace poses
{
class CPose3D;
}
}
#include <mrpt/version.h>

namespace mrpt
{
namespace obs
{
class CObservationBearingRange;
}
}

namespace mrpt_bridge
{
/** @name ObservationRangeBeacon: ROS <-> MRPT
 *  @{ */

/** ROS->MRPT: Takes a mrpt_msgs::ObservationRangeBeacon and the relative pose
 * of the range sensor wrt base_link and builds a CObservationBeaconRanges
  * \return true on sucessful conversion, false on any error.
  * \sa mrpt2ros
  */
bool convert(
  const mrpt_msgs::ObservationRangeBearing& _msg,
	const mrpt::poses::CPose3D& _pose,
  mrpt::obs::CObservationBearingRange& _obj);

/** MRPT->ROS: Takes a CObservationBeaconRanges and outputs range data in
 * mrpt_msgs::ObservationRangeBeacon
  * \return true on sucessful conversion, false on any error.
  * \sa ros2mrpt
  */
bool convert(
  const mrpt::obs::CObservationBearingRange& _obj,
  mrpt_msgs::ObservationRangeBearing& _msg);

/** MRPT->ROS: Takes a CObservationBeaconRanges and outputs range data in
 * mrpt_msgs::ObservationRangeBeacon + the relative pose of the range sensor wrt
 * base_link
  * \return true on sucessful conversion, false on any error.
  * \sa ros2mrpt
  */
bool convert(
  const mrpt::obs::CObservationBearingRange& _obj,
  mrpt_msgs::ObservationRangeBearing& _msg, geometry_msgs::Pose& _pose);

/** @} */

}  // namespace mrpt_bridge

#endif  // MRPT_BRIDGE_BEARING_H
