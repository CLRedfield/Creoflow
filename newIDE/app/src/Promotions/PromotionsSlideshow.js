// @flow
import * as React from 'react';

type PromotionsSlideshowProps = {|
  type?: 'game' | 'asset-pack' | 'game-template',
|};

const PromotionsSlideshow = ({ type }: PromotionsSlideshowProps) => {
  // 禁用广告显示 - 直接返回 null 不渲染任何促销内容
    return null;
};

export default PromotionsSlideshow;
