/*
  Q Light Controller Plus
  vcsoloframe.h

  Copyright (c) Anders Thomsen
                Massimo Callegari

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef VCSOLOFRAME_H
#define VCSOLOFRAME_H

#include "vcwidget.h"
#include "vcframe.h"
#include "function.h"

class QMouseEvent;
class QString;
class Doc;

/** @addtogroup ui_vc_widgets
 * @{
 */

#define KXMLQLCVCSoloFrame       QStringLiteral("SoloFrame")
#define KXMLQLCVCSoloFrameMixing QStringLiteral("Mixing")

class VCSoloFrame : public VCFrame
{
    Q_OBJECT
    Q_DISABLE_COPY(VCSoloFrame)

    /*************************************************************************
     * Initialization
     *************************************************************************/
public:
    VCSoloFrame(QWidget* parent, Doc* doc, bool canCollapse = false);
    virtual ~VCSoloFrame();

    /*************************************************************************
     * Clipboard
     *************************************************************************/
public:
    /** @reimp */
    virtual VCWidget* createCopy(VCWidget* parent);

protected:
    /** Copy the contents for this widget from another widget */
    virtual bool copyFrom(const VCWidget* widget);

    /*************************************************************************
    * Solo behaviour
    *************************************************************************/
public:
    /** Method to connect/disconnect the children widgets
     *  to implement the solo behaviour.
     *  Basically this is called on Doc mode changes */
    void updateChildrenConnection(bool doConnect);

protected:
    /** Method that returns true if $widget's nearest parent
     *  is this Solo Frame. Otherwise false is returned */
    bool thisIsNearestSoloFrameParent(QWidget* widget);

    /** @reimp */
    virtual void setLiveEdit(bool liveEdit);

protected slots:
    virtual void slotModeChanged(Doc::Mode mode);

    /** Slot called when a Function attached to a widget has
     *  been requested to start.
     */
    void slotWidgetFunctionStarting(quint32 fid, qreal intensity);

    /*****************************************************************************
     * Properties
     *****************************************************************************/
protected:
    /** @reimp */
    virtual void editProperties();

    bool m_soloframeMixing;
public:
    bool soloframeMixing() const;
    void setSoloframeMixing(bool soloframeMixing);

    /*************************************************************************
     * Load & Save
     *************************************************************************/
protected:
    virtual QString xmlTagName() const;

    /*************************************************************************
     * Event handlers
     *************************************************************************/
protected:
    virtual void paintEvent(QPaintEvent* e);

};

/** @} */

#endif
