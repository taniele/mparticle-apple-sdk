//
//  MPForwardQueueItem.h
//
//  Copyright 2016 mParticle, Inc.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <Foundation/Foundation.h>
#import "MPEnums.h"
#import "MPKitProtocol.h"

@class MPEvent;
@class MPCommerceEvent;
@class MPKitFilter;
@class MPKitExecStatus;
@class MPForwardQueueParameters;

typedef NS_ENUM(NSUInteger, MPQueueItemType) {
    MPQueueItemTypeEvent = 0,
    MPQueueItemTypeEcommerce,
    MPQueueItemTypeGeneralPurpose
};

@interface MPForwardQueueItem : NSObject

@property (nonatomic, copy, readonly, nullable) void (^completionHandler)(_Nonnull id<MPKitProtocol> kit, MPForwardQueueParameters * _Nullable forwardParameters, MPKitFilter * _Nullable forwardKitFilter, MPKitExecStatus * _Nonnull * _Nonnull execStatus);

@property (nonatomic, unsafe_unretained, readonly) MPMessageType messageType;
@property (nonatomic, unsafe_unretained) MPQueueItemType queueItemType;
@property (nonatomic, unsafe_unretained, readonly, nullable) SEL selector;
@property (nonatomic, strong, readonly, nullable) MPForwardQueueParameters *queueParameters;

- (nullable instancetype)initWithSelector:(nonnull SEL)selector parameters:(nullable MPForwardQueueParameters *)parameters messageType:(MPMessageType)messageType completionHandler:(void (^ _Nonnull)(_Nonnull id<MPKitProtocol> kit, MPForwardQueueParameters * _Nullable forwardParameters, MPKitFilter * _Nullable forwardKitFilter, MPKitExecStatus * _Nonnull * _Nonnull execStatus))completionHandler;

@end
