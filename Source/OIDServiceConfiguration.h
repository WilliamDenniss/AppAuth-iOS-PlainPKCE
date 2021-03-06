/*! @file OIDServiceConfiguration.h
    @brief AppAuth iOS SDK
    @copyright
        Copyright 2015 Google Inc. All Rights Reserved.
    @copydetails
        Licensed under the Apache License, Version 2.0 (the "License");
        you may not use this file except in compliance with the License.
        You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
 */

#import <Foundation/Foundation.h>

@class OIDServiceConfiguration;
@class OIDServiceDiscovery;

NS_ASSUME_NONNULL_BEGIN

/*! @typedef OIDServiceConfigurationCreated
    @brief The type of block called when a @c OIDServiceConfiguration has been created
        by loading a @c OIDServiceDiscovery from an @c NSURL.
 */
typedef void (^OIDServiceConfigurationCreated)
    (OIDServiceConfiguration *_Nullable serviceConfiguration,
     NSError *_Nullable error);

/*! @class OIDServiceConfiguration
    @brief Represents the information needed to construct a @c OIDAuthorizationService.
 */
@interface OIDServiceConfiguration : NSObject <NSCopying, NSSecureCoding>

/*! @property authorizationEndpoint
    @brief The authorization endpoint URI.
 */
@property(nonatomic, readonly) NSURL *authorizationEndpoint;

/*! @property tokenEndpoint
    @brief The token exchange and refresh endpoint URI.
 */
@property(nonatomic, readonly) NSURL *tokenEndpoint;

/*! @property discoveryDocument
    @brief The discovery document.
 */
@property(nonatomic, readonly, nullable) OIDServiceDiscovery *discoveryDocument;

/*! @fn init
    @internal
    @brief Unavailable. Please use @c initWithAuthorizationEndpoint:tokenEndpoint: or
        @c initWithDiscoveryDocument:.
 */
- (nullable instancetype)init NS_UNAVAILABLE;

/*! @fn initWithAuthorizationEndpoint:tokenEndpoint:
    @param authorizationEndpoint The authorization endpoint URI.
    @param tokenEndpoint The token exchange and refresh endpoint URI.
 */
- (nullable instancetype)initWithAuthorizationEndpoint:(NSURL *)authorizationEndpoint
                                         tokenEndpoint:(NSURL *)tokenEndpoint;

/*! @fn initWithDiscoveryDocument:
    @param discoveryDocument The discovery document from which to extract the required OAuth
        configuration.
 */
- (nullable instancetype)initWithDiscoveryDocument:(OIDServiceDiscovery *)discoveryDocument;

@end

NS_ASSUME_NONNULL_END
