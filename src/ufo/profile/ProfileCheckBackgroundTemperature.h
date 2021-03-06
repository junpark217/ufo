/*
 * (C) Crown copyright 2020, Met Office
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 */

#ifndef UFO_PROFILE_PROFILECHECKBACKGROUNDTEMPERATURE_H_
#define UFO_PROFILE_PROFILECHECKBACKGROUNDTEMPERATURE_H_

#include <algorithm>
#include <cmath>
#include <vector>

#include "ufo/profile/ProfileCheckBase.h"
#include "ufo/profile/ProfileCheckValidator.h"
#include "ufo/profile/ProfileDataHandler.h"
#include "ufo/profile/ProfileIndices.h"

#include "ufo/utils/ProbabilityOfGrossError.h"

namespace ioda {
  class ObsSpace;
}

namespace ufo {
  class ProfileConsistencyCheckParameters;
}

namespace ufo {

  /// \brief Profile QC: compare temperature data with model background values
  /// using a Bayesian method.
  /// This check can be performed on both reported level data and on data which have been
  /// averaged onto model levels.
  /// QC flags are not set for reported level data so that all levels
  /// (except those with PGE > 0.999) will be used in vertical averaging.
  class ProfileCheckBackgroundTemperature : public ProfileCheckBase {
   public:
    ProfileCheckBackgroundTemperature(const ProfileConsistencyCheckParameters &options,
                                      const ProfileIndices &profileIndices,
                                      ProfileDataHandler &profileDataHandler,
                                      ProfileCheckValidator &profileCheckValidator);

    /// Run check
    void runCheck() override;

    /// Fill variables in validator
    void fillValidator() override {}
  };
}  // namespace ufo

#endif  // UFO_PROFILE_PROFILECHECKBACKGROUNDTEMPERATURE_H_
